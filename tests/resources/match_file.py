import difflib
import time
from os import path, environ

from robot.api import logger

OUTPUT_DIR = environ['TEST_OUTPUT_DIR']


def _report_diff(compared_file: str, expected: list[str], actual: list[str]):
    def _generate_diff_file_name(compared_file):
        timestamp = time.strftime('%H:%M:%S') + f'{time.time() % 1:0.3}'[1:]
        return f'{path.basename(compared_file)}-diff-{timestamp}.html'

    def _generate_diff_html(expected, actual):
        diff = difflib.HtmlDiff().make_file(expected, actual)
        return diff.replace('font-family:Courier;', 'font-family:Monospace;')

    diff_file = _generate_diff_file_name(compared_file)

    with open(path.join(OUTPUT_DIR, diff_file), 'w') as f:
        f.write( _generate_diff_html(expected, actual) )

    logger.info(f'Output does not match file content, '
                f'<a href="/{diff_file}">see diff</a>', html=True)


def match_file_contents(text: str, file: str):
    with open(file, 'r') as f:
        expected = f.read()

    expected_lines = expected.splitlines()
    text_lines = text.splitlines()

    if expected_lines != text_lines:
        _report_diff(file, expected_lines, text_lines)

        raise AssertionError(f'Content differs:\n' +
            '\n'.join(difflib.unified_diff(expected_lines, text_lines))
        )

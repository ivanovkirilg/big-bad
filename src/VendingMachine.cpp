#include "VendingMachine.hpp"

VendingMachine::VendingMachine()
    : m_balance(0), m_selectedItem("")
{
}

void VendingMachine::stockItem(const std::string& item, int count, int priceCents)
{
    m_items[item].stock += count;
    m_items[item].priceCents = priceCents;
}

void VendingMachine::selectItem(const std::string& item)
{
    if (!m_items.count(item))
    {
        throw VendingMachineError("Item not found");
    }
    if (m_items[item].stock <= 0)
    {
        throw VendingMachineError("Item out of stock");
    }

    m_selectedItem = item;
}

void VendingMachine::insertCoin(int cents)
{
    if (cents <= 0)
    {
        throw VendingMachineError("Inserted coin value must be positive");
    }

    m_balance += cents;
}

void VendingMachine::dispense()
{
    if (m_selectedItem.empty())
    {
        throw VendingMachineError("No item selected");
    }

    auto &info = m_items[m_selectedItem];
    if (info.stock <= 0)
    {
        throw VendingMachineError("Selected item out of stock");
    }
    if (m_balance < info.priceCents)
    {
        throw VendingMachineError("Insufficient balance");
    }

    info.stock--;
    m_balance -= info.priceCents;
    m_selectedItem.clear();
}

int VendingMachine::getBalance() const
{
    return m_balance;
}

int VendingMachine::getItemStock(const std::string& item) const
{
    if (!m_items.count(item))
    {
        throw VendingMachineError("Item not found");
    }

    return m_items.at(item).stock;
}

int VendingMachine::getItemPrice(const std::string& item) const
{
    if (!m_items.count(item))
    {
        throw VendingMachineError("Item not found");
    }

    return m_items.at(item).priceCents;
}

int VendingMachine::refund()
{
    int refundAmount = m_balance;
    m_balance = 0;
    m_selectedItem.clear();
    return refundAmount;
}
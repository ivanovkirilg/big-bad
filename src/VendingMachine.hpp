#ifndef SRC_VENDING_MACHINE
#define SRC_VENDING_MACHINE

#include <string>
#include <unordered_map>
#include <stdexcept>

class VendingMachine
{
public:
    class VendingMachineError : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };

    VendingMachine();

    void stockItem(const std::string& item, int count, int priceCents);

    // General customer flow: select item, insert coins, dispense item, [refund]
    void selectItem(const std::string& item);
    void insertCoin(int cents);
    void dispense();
    int refund();

    int getBalance() const;
    int getItemStock(const std::string& item) const;
    int getItemPrice(const std::string& item) const;

private:
    struct ItemInfo
    {
        int stock;
        int priceCents;
    };
    std::unordered_map<std::string, ItemInfo> m_items;
    std::string m_selectedItem;
    int m_balance;
};


#endif // SRC_VENDING_MACHINE

#include<iostream>
#include<memory>
#include<string>
using namespace std;

/* Product class*/
class Pizza
{
public:
    void setDough(const string& dough)
    {
        m_dough = dough;
    }
    void setSauce(const string& sauce)
    {
        m_sauce = sauce;
    }
    void setTopping(const string& topping)
    {
        m_topping = topping;
    }
    void open() const
    {
        cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
            << m_topping << " topping. Mmm.\n";
    }
private:
    string m_dough;
    string m_sauce;
    string m_topping;
};

/* Abstract Builder class */
class PizzaBuilder
{
public:
    /* virtual destructor should be there if virtual member functions exits */
    virtual ~PizzaBuilder() {};
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    Pizza* getPizza()
    {
        return m_pizza.get();
    }
    void createNewPizzaProduct()
    {
        m_pizza = make_unique<Pizza>();
    }

protected:
    unique_ptr<Pizza> m_pizza;
};

/* Concrete Builder 1 */
class HawaiianPizzaBuilder: public PizzaBuilder
{
    virtual ~HawaiianPizzaBuilder() {};
    virtual void buildDough()
    {
        m_pizza->setDough("cross");
    }
    virtual void buildSauce()
    {
        m_pizza->setSauce("mild");
    }
    virtual void buildTopping()
    {
        m_pizza->setTopping("ham+pineapple");
    }
};

/* Concrete Builder 2 */
class SpicyPizzaBuilder : public PizzaBuilder
{
    virtual ~SpicyPizzaBuilder() {};
    virtual void buildDough()
    {
        m_pizza->setDough("pan baked");
    }
    virtual void buildSauce()
    {
        m_pizza->setSauce("hot");
    }
    virtual void buildTopping()
    {
        m_pizza->setTopping("pepperoni+salami");
    }
};

int main()
{
    std::cout << "let's start!";
    std::cin.get();
    return 0;
}
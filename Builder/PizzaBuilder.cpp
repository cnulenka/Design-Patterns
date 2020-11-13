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
            << m_topping << " topping is ready. Mmm.\n";
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
public:
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
public:
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

/*Director class*/
class Cook
{
public:
    void openPizza()
    {
        m_pizzaBuilder->getPizza()->open();
    }
    /* Pizza contruction takesplace as per the builder type*/
    void makePizza(PizzaBuilder* pb)
    {
        m_pizzaBuilder = pb;
        m_pizzaBuilder->createNewPizzaProduct();
        m_pizzaBuilder->buildDough();
        m_pizzaBuilder->buildSauce();
        m_pizzaBuilder->buildTopping();
    }
private:
    /* parent class pointer can store any child class object */
    PizzaBuilder* m_pizzaBuilder;
};

/* client code, used to create and open pizza */
int main()
{
    Cook cook;
    HawaiianPizzaBuilder hawaiian_pizza_builder;
    SpicyPizzaBuilder    spicy_pizza_builder;

    cook.makePizza(&hawaiian_pizza_builder);
    cook.openPizza();

    cook.makePizza(&spicy_pizza_builder);
    cook.openPizza();

    /* press enter to close the cmd */
    std::cin.get();
    return 0;
}
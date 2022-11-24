#include <iostream>


class animal
{
    private:
        std::string m_sname;
        int m_nid;
    public:
        animal()
        : m_sname ("aaa")
        , m_nid (1)
        {}
        animal(std::string name , int id)
        : m_sname (name)
        , m_nid (id)
        {}
        virtual void toFeed()
        {
            std::cout<<"I am not eat."<<std::endl;
        }
        virtual void makeSound()
        {
            std::cout<<"I haven't voice."<<std::endl;
        }
        int getId(){
            return m_nid;
        }
        std::string getName(){
            return m_sname;
        }
        void setId(int new_id){
            this->m_nid = new_id;
        }
        void setName(std::string new_name) {
            this->m_sname = new_name;
        }
};

class cat: public animal
{
    private:
        std::string m_sbreed;
        std::string m_scolor;
    public:
        cat ()
        :animal()
        ,m_sbreed("am")
        ,m_scolor("black")
        {}
        cat  (std::string name , int id , std::string breed , std:: string color)
        :animal (name , id)
        ,m_sbreed(breed)
        ,m_scolor(color)
        {}
        void toFeed() override
        {
            std::cout<<"I eat fish."<<std::endl;
        }
        void makeSound() override
        {
            std::cout<<"My voice is miau."<<std::endl;
        }
        std::string getBreed(){
            return m_sbreed;
        }
        std::string getColor(){
            return m_scolor;
        }
        void setBreed(std::string new_breed) {
            this->m_sbreed = new_breed;
        }
        void setColor(std::string new_color) {
            this->m_scolor = new_color;
        }
};

class dog: public animal
{
    private:
        std::string m_sbreed;
        std::string m_scolor;
    public:
        dog ()
        :animal()
        ,m_sbreed("am")
        ,m_scolor("black")
        {}
        dog  (std::string name , int id , std::string breed , std:: string color)
        :animal (name , id)
        ,m_sbreed(breed)
        ,m_scolor(color)
        {}
        void toFeed() override
        {
            std::cout<<"I eat meat."<<std::endl;
        }
        void makeSound() override
        {
            std::cout<<"My voice is haf."<<std::endl;
        }
                std::string getBreed(){
            return m_sbreed;
        }
        std::string getColor(){
            return m_scolor;
        }
        void setBreed(std::string new_breed) {
            this->m_sbreed = new_breed;
        }
        void setColor(std::string new_color) {
            this->m_scolor = new_color;
        }
};

int main(){
    cat c("hay" , 3 ,  "h" , "white");
    std::cout<<c.getName()<<std::endl;
    std::cout<<c.getId()<<std::endl;
    std::cout<<c.getBreed()<<std::endl;
    std::cout<<c.getColor()<<std::endl;

    c.setName("A");
    c.setId(2);
    c.setBreed("etsvj");
    c.setColor("red");
    

    c.makeSound();
    c.toFeed();

    std::cout<<c.getName()<<std::endl;
    std::cout<<c.getId()<<std::endl;
    std::cout<<c.getBreed()<<std::endl;
    std::cout<<c.getColor()<<std::endl;
    return 0;

}
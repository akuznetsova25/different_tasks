#include <iostream>
#include <string>
#include <sstream>
#include <vector>



class human 
{
public:
    human(std::string name, std::string last_name, std::string second_name)
    {
        this->last_name = last_name;
        this->name = name;
        this->second_name = second_name;
    }

    std::string get_full_name()
    {
        std::ostringstream full_name;
        full_name << this->last_name << " " << this->name << " " << this->second_name;
        return full_name.str();
    }

private:
    std::string name;
    std::string last_name;
    std::string second_name;
};



class student : public human
{
public:
    student(std::string last_name, std::string name, std::string second_name) : human(last_name, name, second_name)
    {
        this->scores = scores;
    }

    float get_average_score()
    {
        unsigned int count_scores = this->scores.size();
        unsigned int sum_scores = 0;
        float average_score;
        for (unsigned int i = 0; i < count_scores; ++i)
        {
            sum_scores += this->scores[i];
        }

        average_score = (float)sum_scores / (float)count_scores;
        return average_score;
    }

private:
    std::vector <double> scores;
};



int main()
{

    return 0;
}



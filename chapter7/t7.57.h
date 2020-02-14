/*************************************************************************************
* Copyright (c) 2019 xffish
* c_plus_plus_primer_exercise is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
* http://license.coscl.org.cn/MulanPSL2
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
* See the Mulan PSL v2 for more details.
*************************************************************************************/

#include <string>
#include <iostream>

class Account
{
public:
    Account();
    Account(const std::string &owner);
    Account(const std::string &owner, const double &amount);

    const std::string& getOwner();
    const double& getAmount();
    static const double& getInterestRate();

    static void setInterestRate(const double& rate);

    void display();
private:
    std::string owner;
    double amount;
    static double interestRate;
};

double Account::interestRate = 0;

Account::Account():Account("", 0.0)
{

}

Account::Account(const std::string &owner) : Account(owner, 0.0)
{
}

Account::Account(const std::string &owner, const double &amount) : owner(owner), amount(amount)
{
}

const std::string& Account::getOwner()
{
    return owner;
}


const double& Account::getAmount()
{
    return amount;
}


const double& Account::getInterestRate()
{
    return interestRate;
}

void Account::setInterestRate(const double& rate)
{
    interestRate = rate;
}

void Account::display()
{
    std::cout << owner << "---" << amount << "---" << Account::interestRate << std::endl; //显式使用静态变量
}
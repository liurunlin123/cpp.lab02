#pragma once
#ifndef CARD_OPERATIONS_H
#define CARD_OPERATIONS_H

#include <string>

struct Card {
    int id;
    std::string name;
    double balance;
    int transactions;
};

constexpr double FEE_RATE = 0.02;

namespace card {
    void printLine(char c = '-', int len = 60);
    void title(const std::string& s);
}

Card* createCards(int n);
void inputCards(Card* arr, int n);
void destroyCards(Card* arr);

void deposit(Card& c, double amount, double fee = FEE_RATE);
bool spend(Card& c, double cost);
bool spend(Card& c, double cost, const std::string& item);

void showBalance(const Card& c);
void viewStudentID(const Card* p);
int toCent(double amount);
void printReport(const Card* arr, int n);

#endif

#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "stack.h"
#include "calculator.h"
#include <iostream>

class StackTests : public QObject
{
     Q_OBJECT
public:
    explicit StackTests(QObject *parent = 0) : QObject(parent) {}

private:
    Stack* arrayStack;
    Stack* listStack;

private slots:
    void initTestCase()
    {
        arrayStack = stackCreator(2);
        listStack = stackCreator(1);
    }
    void testEmptyArr()
    {
        QCOMPARE(arrayStack->empty(), true);
        arrayStack->push('6');
        QCOMPARE(arrayStack->empty(), false);
        arrayStack->pop();
        QCOMPARE(arrayStack->empty(), true);
    }
    void testEmptyList()
    {
        QCOMPARE(listStack->empty(), true);
        listStack->push('6');
        QCOMPARE(listStack->empty(), false);
        listStack->pop();
        QCOMPARE(arrayStack->empty(), true);
    }
    void testExpressionList()
    {
        char* str = new char[1000];
        for(int i = 0; i < 1000; i++)
            str[i] = '\n';
        str = "2+2*3";
        QCOMPARE(calculator(listStack, str), 8);
    }
    void testExpressionArr()
    {
        char* str = new char[1000];
        for(int i = 0; i < 1000; i++)
            str[i] = '\n';
        str = "(2+2)*3";
        QCOMPARE(calculator(arrayStack, str), 12);
    }
    void testPushArr()
    {
        arrayStack->push('1');
        QCOMPARE(arrayStack->top(), '1');
    }
    void testPushList()
    {
        listStack->push('1');
        QCOMPARE(listStack->top(), '1');
    }
    void testPopArr()
    {
        arrayStack->push('6');
        arrayStack->push('1');
        arrayStack->pop();
        QCOMPARE(arrayStack->top(), '6');
    }
    void testPopList()
    {
        listStack->push('1');
        listStack->push('9');
        listStack->pop();
        QCOMPARE(listStack->top(), '1');
    }
    void cleanupTestCase()
    {
        delete arrayStack;
        delete listStack;
    }
};

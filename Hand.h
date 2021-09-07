#pragma once
#include <vector>
#include "Card.h"

class Hand {
protected:
    std::vector<Card*> m_Cards;  // Коллекция карт. Хранит указатели на объекты типа Сard
public:
    Hand();
    virtual ~Hand();

    void Add(Card* pCard) { //Добавляет карту в руку. Добавляет указатель на объект типа Сard в вектор m_Сards
        m_Cards.push_back(pCard);
    }

    void Clear() { //Очищает руку от карт. Удаляет все указатели из вектора m_Сards, устраняя все связанные с ними объекты в куче
        /* ERROR: munmap_chunk(): invalid pointer
         * std::vector<Card*>::iterator it = m_Cards.begin();
        for(it = m_Cards.begin(); it != m_Cards.end(); ++it){
            delete *it;
            *it = 0;
        }
         */
        m_Cards.clear();
    }

    int GetTotal() { //Возвращает сумму очков карт руки
        int total = 0;
        if(m_Cards.size() == 0){
            return 0;
        }
        for(int i = 0; i < m_Cards.size(); ++i){
            total += (int)m_Cards.at(i)->getValue();
        }
        return total;
    }

};

Hand::Hand() {

}

Hand::~Hand() {

}


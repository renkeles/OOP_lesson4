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
		m_Cards.clear();
	}

	int GetTotal() { //Возвращает сумму очков карт руки
		
	}

};

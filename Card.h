#pragma once

enum class Suit { //Масть карты (трефы, бубны, червы и пики)
    HEART = 0,
    DIAMOND = 1,
    CLUB = 2,
    SPADE = 3
};
enum class Value{ // Значение карты (туз, двойка, тройка и так долее)
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    ACE = 11,
    JACK = 12,
    QUEEN = 13,
    KING = 14
};

class Card {
private:
    Suit _suit;
    Value _value;
    bool _faceDown;  //Указывает, как расположена карта — вверх лицом или рубашкой.Влияет на то, отображается она или нет
public:
    Card(Suit suit, Value value, bool faceDown) : _suit(suit), _value(value), _faceDown(faceDown) {}
    Suit getSuit() {
        return _suit;
    }
    Value getValue() { //Возвращает значение карты
        return _value;
    }
    bool getFaceDown() {
        return _faceDown;
    }

    bool setFaceDown(bool faceDown) {
        _faceDown = faceDown;

        return _faceDown;
    }

    bool Flip(Card& card) { //Переворачивает карту. Может использоваться для того, чтобы перевернуть карту лицом вверх или вниз
        return card.setFaceDown(!card.getFaceDown());
    }
};

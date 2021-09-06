#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert>

class ArrayInt
{
private:
    int m_length;
    int* m_data;

    void swap(int* a, int* b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) :
            m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }


    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];

        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }

    void print(){
        for(int i = 0; i < m_length; i++){
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }

    void sort(){
        for(int i = 1; i < m_length; i++){
            int k = i;
            while(k > 0 && m_data[k - 1] < m_data[k]){
                swap(&m_data[k], &m_data[k - 1]);
                k -= 1;
            }
        }
    }

    int pop_front(){
        if(m_length == 0) return 0;

        int tmp = m_data[0];
        for(int i = 0; i < m_length - 1; i++){
            swap(&m_data[i], &m_data[i + 1]);
        }
        --m_length;
        return tmp;
    }

    int pop_back(){
        if(m_length == 0) return 0;

        int tmp = m_data[m_length - 1];
        --m_length;
        return tmp;
    }

};



#endif

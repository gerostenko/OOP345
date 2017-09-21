///OOP345 Workshop 3: Templates 
// File: KVList.h
// Version: 1.0
// Date: 2017/09/21
// Author: Galina Erostenko
// Description: Template implementation
///////////////////////////////////////////////////

#ifndef W3_KVLIST_H__
#define W3_KVLIST_H__

namespace w3 {
    template <typename K, typename V, int N>
    class KVList {
        K m_kValues[N]; 
        V m_values[N];
        size_t counter;
        K dummyK;
        V dummyV;
    public:
        KVList()
        {
            counter = 0;
        }
        size_t size() const
        {
            return counter;
        }
        const K& key(int i) const
        {
            return i < counter ? m_kValues[i] : dummyK;
        }
        const V& value(int i) const
        {
            return i < counter ? m_values[i] : dummyV;
        }
        KVList& add(const K& kValue, const V& value)
        {
            if (counter < N)
            {
                m_kValues[counter] = kValue;
                m_values[counter] = value;
                counter++;
            }
            return *this;
        }
        int find(const K& k) const
        {
            
            for (int i = 0; i < N; i++)
            {
                if (m_kValues[i] == k)
                    return i;
            }
            return 0;
        
        }
        KVList& replace(int i, const K& k, const V& v)
        {
            if (i < counter)
            {
                m_kValues[i] = k;
                m_values[i] = v;
            }
            return *this;
        }
    };

}

#endif
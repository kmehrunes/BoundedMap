#ifndef BOUNDED_MAP_H
#define BOUNDED_MAP_H

#include <deque>

template<typename map_t, typename key_t, typename value_t, unsigned cap>
class static_bounded_map
{
public:
    /**
     * @throws exception!
     */
    void insert(std::pair<key_t, value_t> entry)
    {
        m_map.insert(entry);
        m_keys.push_back(entry.first);
        if (m_keys.size() > cap)
            remove_oldest();
    }

    value_t & at(key_t key)
    {
        return m_map.at(key);
    }

    typename map_t::size_type size()
    {
        return m_map.size();
    }

    typename map_t::iterator begin()
    {
        return m_map.begin();
    }

    typename map_t::iterator cbegin()
    {
        return m_map.cbegin();
    }

    typename map_t::iterator end()
    {
        return m_map.end();
    }

    typename map_t::iterator cend()
    {
        return m_map.cend();
    }

private:
    /**
     * @brief remove_last
     * @throws An exception if any operation on internal
     * structures threw one.
     */
    void remove_oldest()
    {
        key_t & front = m_keys.front();
        m_map.erase(front);
        m_keys.pop_front();
    }

private:
    std::deque<key_t> m_keys;
    map_t m_map;
};


template<typename map_t, typename key_t, typename value_t>
class bounded_map
{
public:
    bounded_map(unsigned cap)
    {
        m_cap = cap;
    }

    /**
     * @throws exception!
     */
    void insert(std::pair<key_t, value_t> entry)
    {
        m_map.insert(entry);
        m_keys.push_back(entry.first);
        if (m_keys.size() > m_cap)
            remove_oldest();
    }

    value_t & at(key_t key)
    {
        return m_map.at(key);
    }

    typename map_t::size_type size()
    {
        return m_map.size();
    }

    typename map_t::iterator begin()
    {
        return m_map.begin();
    }

    typename map_t::iterator cbegin()
    {
        return m_map.cbegin();
    }

    typename map_t::iterator end()
    {
        return m_map.end();
    }

    typename map_t::iterator cend()
    {
        return m_map.cend();
    }

private:
    /**
     * @brief remove_last
     * @throws An exception if any operation on internal
     * structures threw one.
     */
    void remove_oldest()
    {
        key_t & front = m_keys.front();
        m_map.erase(front);
        m_keys.pop_front();
    }

private:
    std::deque<key_t> m_keys;
    map_t m_map;
    unsigned m_cap;
};


#endif // BOUNDED_MAP_H

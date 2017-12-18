# BoundedMap
An implementation of a size-bounded map container. It's useful when implementing a fixed-size buffer which needs to also have access by key. This was implemented initially for a TCP packets buffer where packets could arbitrarly be retrieved by their sequence numbers.

## Example
Instead of specifying an internal map structure, the map type is given as a template parameter.

### static_bounded_map
This class requires the size to be specified at compile-time as a template parameter
```C++
#define CAPACITY 3
static_bounded_map<unordered_map<string, int>, string, int, CAPACITY> map;
```

### bounded_map
This one takes the capacity in the constructor
```C++
#define CAPACITY 3
bounded_map<unordered_map<string, int>, string, int> map(CAPACITY);
```

After that you have access to insert(), size(), begin(), cbegin(), end(), and cend() functions.

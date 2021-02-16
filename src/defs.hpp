#include <cstddef>
#include <cstdlib>

#define DECLARE_ONE_WAY_NODE_POINTER (OneWayNode<T> *)malloc(sizeof(OneWayNode<T>))
#define DECLARE_TWO_WAY_NODE_POINTER (TwoWayNode<T> *)malloc(sizeof(TwoWayNode<T>))
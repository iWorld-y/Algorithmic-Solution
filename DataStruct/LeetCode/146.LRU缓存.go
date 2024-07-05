package LeetCode

type DList[T comparable] struct {
	head *Node[T]
	tail *Node[T]
	len  int
	cap  int
}

type Node[T comparable] struct {
	next *Node[T]
	prev *Node[T]
	key  T
	val  T
}

func NewDList[T comparable](cap int) *DList[T] {
	l := &DList[T]{}
	l.len = 0
	l.cap = cap
	return l
}

func (l *DList[T]) Insert(key, val T) *DList[T] {
	node := &Node[T]{
		key: key,
		val: val,
	}
	if l.head == nil || l.tail == nil {
		l.head = node
		l.tail = node
	} else {
		if l.len >= l.cap {
			l.tail.key = key
			l.tail.val = val
			l.MoveToFront(l.tail)
			return l
		}
		l.head.prev = node
		node.next = l.head
		l.head = node
	}
	l.len++
	return l
}

func (l *DList[T]) MoveToFront(node *Node[T]) *DList[T] {
	if node.prev != nil && node.next != nil {
		node.prev.next = node.next
		node.next.prev = node.prev

		node.prev = nil
		node.next = l.head
		l.head.prev = node
		l.head = node
		return l
	}
	if node.prev == nil {
		return l
	}

	l.tail = l.tail.prev
	l.tail.next = nil
	l.head.prev = node
	node.next = l.head
	l.head = node
	l.head.prev = nil
	return l
}

type LRUCache struct {
	cache map[int]*Node[int]
	ll    DList[int]
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		cache: make(map[int]*Node[int], capacity),
		ll:    *NewDList[int](capacity),
	}
}

func (lru *LRUCache) Get(key int) int {
	if node, ok := lru.cache[key]; ok {
		lru.ll.MoveToFront(node)
		return node.val
	}
	return -1
}

func (lru *LRUCache) Put(key int, value int) {
	if lru.Get(key) == -1 {
		if lru.ll.len >= lru.ll.cap {
			delete(lru.cache, lru.ll.tail.key)
		}
		lru.ll.Insert(key, value)
		lru.cache[key] = lru.ll.head
		return
	}
	lru.cache[key].val = value
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

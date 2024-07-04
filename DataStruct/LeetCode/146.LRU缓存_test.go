package LeetCode

import "testing"

func TestConstructor(t *testing.T) {
	lRUCache := Constructor(2)
	lRUCache.Put(1, 1) // 缓存是 {1=1}
	lRUCache.Put(2, 2) // 缓存是 {1=1, 2=2}
	if lRUCache.Get(1) != 1 {
		// 返回 1
		t.Fatalf("lRUCache.Get(1) != 1")
	}
	lRUCache.Put(3, 3) // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
	if lRUCache.Get(2) != -1 {
		// 返回 -1 (未找到)
		t.Fatalf("lRUCache.Get(2) != -1")

	}
	lRUCache.Put(4, 4) // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
	if lRUCache.Get(1) != -1 {
		// 返回 -1 (未找到)
		t.Fatalf("lRUCache.Get(1)!=-1")
	}
	if lRUCache.Get(3) != 3 {
		// 返回 3
		t.Fatalf("lRUCache.Get(3)!= 3")
	}
	if lRUCache.Get(4) != 4 {
		// 返回 4
		t.Fatalf("lRUCache.Get(4)!= 4")
	}
}

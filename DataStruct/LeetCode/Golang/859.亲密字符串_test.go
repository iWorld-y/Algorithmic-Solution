package LeetCode

import "testing"

func Test_buddyStrings(t *testing.T) {
	var cases = []CommonCase[[]string, bool]{{
		Input:  []string{"aaaaaaabc", "aaaaaaacb"},
		Answer: true,
	}, {
		Input:  []string{"ab", "ba"},
		Answer: true,
	}, {
		Input:  []string{"ab", "ab"},
		Answer: false,
	}, {
		Input:  []string{"aa", "aa"},
		Answer: true,
	}}
	for i, v := range cases {
		if buddyStrings(v.Input[0], v.Input[1]) != v.Answer {
			t.Fatalf("fail at %d", i)
		}
	}
}

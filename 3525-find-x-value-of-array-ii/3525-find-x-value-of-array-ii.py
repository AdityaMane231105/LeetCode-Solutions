class Solution:
    def resultArray(self, nums: list[int], k: int, queries: list[list[int]]) -> list[int]:
        n = len(nums)
        
        # Segment tree arrays to store range products and prefix counts mod k
        tree_prod = [1] * (4 * n)
        tree_counts = [[0] * k for _ in range(4 * n)]

        # Helper function to merge two segment tree nodes
        def merge(left_prod, left_counts, right_prod, right_counts):
            m_prod = (left_prod * right_prod) % k
            m_counts = list(left_counts)
            for r_val in range(k):
                if right_counts[r_val] > 0:
                    new_rem = (left_prod * r_val) % k
                    m_counts[new_rem] += right_counts[r_val]
            return m_prod, m_counts

        # Build the initial segment tree
        def build(tree_idx, l, r):
            if l == r:
                val = nums[l] % k
                tree_prod[tree_idx] = val
                tree_counts[tree_idx][val] = 1
                return
            mid = (l + r) // 2
            left_idx = 2 * tree_idx + 1
            right_idx = 2 * tree_idx + 2
            build(left_idx, l, mid)
            build(right_idx, mid + 1, r)
            tree_prod[tree_idx], tree_counts[tree_idx] = merge(
                tree_prod[left_idx], tree_counts[left_idx],
                tree_prod[right_idx], tree_counts[right_idx]
            )

        # Update a single element in the segment tree
        def update(tree_idx, l, r, idx, val):
            if l == r:
                tree_counts[tree_idx][tree_prod[tree_idx]] = 0
                v = val % k
                tree_prod[tree_idx] = v
                tree_counts[tree_idx][v] = 1
                return
            mid = (l + r) // 2
            left_idx = 2 * tree_idx + 1
            right_idx = 2 * tree_idx + 2
            if idx <= mid:
                update(left_idx, l, mid, idx, val)
            else:
                update(right_idx, mid + 1, r, idx, val)
            tree_prod[tree_idx], tree_counts[tree_idx] = merge(
                tree_prod[left_idx], tree_counts[left_idx],
                tree_prod[right_idx], tree_counts[right_idx]
            )

        # Query a range [ql, qr] from the segment tree
        def query(tree_idx, l, r, ql, qr):
            if ql <= l and r <= qr:
                return tree_prod[tree_idx], tree_counts[tree_idx]
            mid = (l + r) // 2
            left_idx = 2 * tree_idx + 1
            right_idx = 2 * tree_idx + 2
            if qr <= mid:
                return query(left_idx, l, mid, ql, qr)
            if ql > mid:
                return query(right_idx, mid + 1, r, ql, qr)
            
            left_prod, left_counts = query(left_idx, l, mid, ql, qr)
            right_prod, right_counts = query(right_idx, mid + 1, r, ql, qr)
            return merge(left_prod, left_counts, right_prod, right_counts)

        # Initialize the tree
        build(0, 0, n - 1)
        
        ans = []
        # Process each query sequentially
        for index_i, value_i, start_i, x_i in queries:
            update(0, 0, n - 1, index_i, value_i)
            _, counts = query(0, 0, n - 1, start_i, n - 1)
            ans.append(counts[x_i])
            
        return ans

# Definition for singly-linked list.
# class ListNode
#   attr_accessor :val, :next
#   def initialize(val = 0, _next = nil)
#     @val = val
#     @next = _next
#   end
# end

def reverse_k_group(head, k)
  dummy = ListNode.new(0)
  dummy.next = head
  prev_group = dummy

  loop do
    # Find kth node
    kth = get_kth_node(prev_group, k)
    break if kth.nil?

    next_group = kth.next
    prev = next_group
    curr = prev_group.next

    # Reverse k nodes
    while curr != next_group
      temp = curr.next
      curr.next = prev
      prev = curr
      curr = temp
    end

    # Reconnect groups
    temp = prev_group.next
    prev_group.next = kth
    prev_group = temp
  end

  dummy.next
end

def get_kth_node(curr, k)
  while curr && k > 0
    curr = curr.next
    k -= 1
  end
  curr
end
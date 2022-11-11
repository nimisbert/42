# Notes about algorithms and data structures

## PTR : pointer memo

## SLL : simple linked list

Node : <br>
[data | ptr] <br>
Simple linked list : <br>
[headData | headPtr] -> ... -> [data | ptr] -> [data | ptr] -> ... -> [tailData | tailPtr]

Datas : <br>
- [X] Nodes
- [X] SimpleLinkedList

Specs : <br>
- [ ] getSize : return the size, in Nodes, of the list
- [ ] getHead : return the Head of the list
- [ ] getTail : return the Tail of the list
- [ ] getNext : return the node next to the parameter node
- [X] init : initialize the list
- [ ] destroy : clean the list from heap
- [ ] insertNext : insert an node next to the parameter node
- [ ] removeNext : remove the node next to the parameter node
- [ ] reverse : reverse the SLL
- [ ] isHead : set if parameter node is head, clear otherwise
- [ ] isTail : set if parameter node is tail, clear otherwise
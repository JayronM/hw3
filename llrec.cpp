#include "llrec.h"

using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


// void pivHelper(Node* head, Node*& smaller, Node*& smallerT, Node*& larger, Node*& largerT, int pivot){
//   if(!head) return;//base case
	
// 	//std::cout<<"Processing: "<<head->val<<std::endl;

//   Node* nextNode = head->next;
// 	head->next=nullptr; //detach
	
//   if (head->val <= pivot){
// 		if(!smaller){
// 			smaller=head;
// 			smallerT=head;
// 		} else{
// 			smallerT->next =head;
// 			smallerT=head;
// 		}
// 		// head->next = smaller;
// 		// smaller = head;
// }

//   //   if(smaller){
// 	// 		smaller = head; // current node is smaller
// 	// 	} else{
// 	// 		Node* temp = smaller;
// 	// 		while(temp->next) temp = temp->next;
// 	// 		temp->next=head;
// 	// 	}
// 	// } else{
// 	// 	if(!larger){
// 	// 		larger=head;
// 	// 	}else{
// 	// 		Node* temp = larger;
//   //   	while(temp->next) temp = temp->next;
// 	// 		temp->next = head;//curent node is larger

// 	// 	}
// 	// }
// 	else{
// 		if(!larger){
// 			larger=head;
// 			largerT=head;
// 		} else{
// 			largerT->next =head;
// 			largerT=head;
// 		}
// 		// head->next=larger;
// 		// larger= head;

// 	// head->next = nullptr;
		
// 	}
// 	pivHelper(nextNode, smaller, smallerT, larger, largerT, pivot);
	
// }

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
	if(!head){
		smaller = nullptr;
		larger = nullptr;
		return;
	}
  
	Node* nextNode =head->next;
	head->next = nullptr;

	if(head->val <= pivot){
		smaller = head;
		llpivot(nextNode, smaller->next, larger, pivot);
	}else{
		larger = head;
		llpivot(nextNode, smaller, larger->next, pivot);
	}
	head =nullptr;
}
//  Programmed by John Costello.
//  2023 August 13th.

#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode{
      int val;
      struct ListNode* next;
}; 


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
   struct ListNode* currentNodeList1 = list1;
   struct ListNode* currentNodeList2 = list2;
   struct ListNode* currentNodeList3 = NULL;
   struct ListNode* aheadNodeList1 = (&list1!=NULL)?list1->next:NULL;
   struct ListNode* aheadNodeList2 = (&list2!=NULL)?list2->next:NULL;
   struct ListNode* aheadNodeList3 = NULL;
   struct ListNode* previousNodeList1 = NULL;
   struct ListNode* previousNodeList2 = NULL;
   struct ListNode* previousNodeList3 = NULL;
   struct ListNode* list3 = NULL;
   
   if(currentNodeList1!=NULL || currentNodeList2!=NULL)
   {
      if(currentNodeList1!=NULL && currentNodeList2!=NULL)
      {
         if(currentNodeList1->val<=currentNodeList2->val)
         {
            currentNodeList3=currentNodeList1;
            aheadNodeList1=currentNodeList1->next;
            aheadNodeList2=currentNodeList2;
         }
         else
         {
            currentNodeList3=currentNodeList2;
            aheadNodeList2=currentNodeList2->next;
            aheadNodeList1=currentNodeList1;
         }
      }
      else if(currentNodeList1!= NULL)
      {
         currentNodeList3=currentNodeList1;
         aheadNodeList1=currentNodeList1->next;
         aheadNodeList2=currentNodeList2;
      }
      else if(currentNodeList2!=NULL)
      {
         currentNodeList3=currentNodeList2;
         aheadNodeList2=currentNodeList2->next;
         aheadNodeList1=currentNodeList1;
      }
   }
   list3=currentNodeList3;
   while(aheadNodeList1 != NULL || aheadNodeList2 != NULL)
   {
      if(aheadNodeList1 != NULL && aheadNodeList2 != NULL)
      {
         if(aheadNodeList1->val <= aheadNodeList2->val)
         {
            aheadNodeList3 = aheadNodeList1;
            currentNodeList3->next = aheadNodeList3;
            aheadNodeList1 = aheadNodeList1->next;
            currentNodeList3 = aheadNodeList3;
         }
         else
         {
            aheadNodeList3 = aheadNodeList2;
            currentNodeList3->next = aheadNodeList3;
            aheadNodeList2 = aheadNodeList2->next;
            currentNodeList3 = aheadNodeList3;
         }
      }
      else if(aheadNodeList1 != NULL)
      {
         aheadNodeList3 = aheadNodeList1;
         currentNodeList3->next = aheadNodeList3;
         aheadNodeList1 = aheadNodeList1->next;
         currentNodeList3 = aheadNodeList3;
      }
      else if(aheadNodeList2 != NULL)
      {
         aheadNodeList3 = aheadNodeList2;
         currentNodeList3->next = aheadNodeList3;
         aheadNodeList2 = aheadNodeList2->next;
         currentNodeList3 = aheadNodeList3;
      }
   }
   return(list3);
}

int main()
{  
   struct ListNode LNarray1[3], LNarray2[3];
   
   int array1[3] = {1,4,7};
   int array2[3] = {2,6,8};
   
   for(int i=2; i>=0; i--)
   {
      LNarray1[i].val=array1[i];
      if(i==2){    LNarray1[i].next = NULL;    }
      else{    LNarray1[i].next = &LNarray1[i+1];    }
   }
   struct ListNode* list1 = &LNarray1[0]; 

   for(int i=2; i>=0; i--)
   {
      LNarray2[i].val=array2[i];
      if(i==2){    LNarray2[i].next = NULL;    }
      else{    LNarray2[i].next = &LNarray2[i+1];    }
   }
   struct ListNode* list2 = &LNarray2[0];
   
   struct ListNode* thisNode;

   printf("--------------------\n");
   printf("----- List 1 -------\n");
   printf("--------------------\n");
   thisNode = list1;
   do
   {
      if(thisNode != NULL)
      {   
         printf("%d     this: %p    next: %p\n",thisNode->val,thisNode,thisNode->next);
         thisNode=thisNode->next;
      }
   }while(thisNode != NULL);

   printf("--------------------\n");
   printf("----- List 2 -------\n");
   printf("--------------------\n");
   thisNode = list2;
   do
   {
      if(thisNode != NULL)
      {   
         printf("%d     this: %p    next: %p\n",thisNode->val,thisNode,thisNode->next);
         thisNode=thisNode->next;
      }
   }while(thisNode != NULL);

   printf("--------------------\n");
   printf("---- Merged List ---\n");
   printf("--------------------\n");

   struct ListNode* list3 = mergeTwoLists(list1, list2);
   thisNode = list3;
   do
   {
      if(thisNode != NULL)
      {   
         printf("%d     this: %p    next: %p\n",thisNode->val,thisNode,thisNode->next);
         thisNode=thisNode->next;
      }
   }while(thisNode != NULL);

   return(0);
}


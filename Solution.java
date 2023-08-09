class Solution
{
    public ListNode mergeTwoLists(ListNode list1, ListNode list2)
    {
        
        ListNode currentNodeList1=list1;
        ListNode currentNodeList2=list2;
        ListNode currentNodeList3=null;
        ListNode aheadNodeList1=(list1!=null)?list1.next:null;
        ListNode aheadNodeList2=(list2!=null)?list2.next:null;
        ListNode aheadNodeList3=null;
        ListNode previousNodeList1=null;
        ListNode previousNodeList2=null;
        ListNode previousNodeList3=null;
        ListNode list3=null;
        
        if(currentNodeList1!=null || currentNodeList2!=null)
        {
            if(currentNodeList1!=null && currentNodeList2!=null)
            {
                if(currentNodeList1.val<=currentNodeList2.val)
                {
                    currentNodeList3=currentNodeList1;
                    aheadNodeList1=currentNodeList1.next;
                    aheadNodeList2=currentNodeList2;
                }
                else
                {
                    currentNodeList3=currentNodeList2;
                    aheadNodeList2=currentNodeList2.next;
                    aheadNodeList1=currentNodeList1;
                }
            }
            else if(currentNodeList1!=null)
            {
                currentNodeList3=currentNodeList1;
                aheadNodeList1=currentNodeList1.next;
                aheadNodeList2=currentNodeList2;
            }
            else if(currentNodeList2!=null)
            {
                currentNodeList3=currentNodeList2;
                aheadNodeList2=currentNodeList2.next;
                aheadNodeList1=currentNodeList1;
            }
        }
        list3=currentNodeList3;
        
        while(aheadNodeList1!=null || aheadNodeList2!=null)
        {
            if(aheadNodeList1!=null && aheadNodeList2!=null)
            {
                if(aheadNodeList1.val<=aheadNodeList2.val)
                {
                    aheadNodeList3=aheadNodeList1;
                    currentNodeList3.next=aheadNodeList3;
                    aheadNodeList1=aheadNodeList1.next;
                    currentNodeList3=aheadNodeList3;
                }
                else
                {
                    aheadNodeList3=aheadNodeList2;
                    currentNodeList3.next=aheadNodeList3;
                    aheadNodeList2=aheadNodeList2.next;
                    currentNodeList3=aheadNodeList3;
                }
            }
            else if(aheadNodeList1!=null)
            {
                aheadNodeList3=aheadNodeList1;
                currentNodeList3.next=aheadNodeList3;
                aheadNodeList1=aheadNodeList1.next;
                currentNodeList3=aheadNodeList3;
            }
            else if(aheadNodeList2!=null)
            {
                aheadNodeList3=aheadNodeList2;
                currentNodeList3.next=aheadNodeList3;
                aheadNodeList2=aheadNodeList2.next;
                currentNodeList3=aheadNodeList3;
            }
        }
        return list3;
    }
}

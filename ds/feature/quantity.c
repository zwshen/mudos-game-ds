// /feature/quantiy.c		by shengsan@DS
// #pragma save_binary
#include <dbase.h>




/*
*  �N���Ҫ����e���@�Ƨ�
*/
mixed *sortinv(object env)
{
	object *inv;
	object invtmp;

	if(!env) return 0;
	inv = all_inventory(env);
	inv = sort_array(inv, "sort_item", this_object());
//	for(i=0;i<sizeof(inv);i++)
//	for(j=i;j<sizeof(inv);j++)
//	{
//		if( !(strcmp(base_name(inv[i]),base_name(inv[j]))==0
//		&& base_name(inv[i]) == "/obj/user") )
//		if( strcmp(base_name(inv[i]),base_name(inv[j]))==1 )
//		{
//			invtmp = inv[j];
//			for(k=j;k>=i+1;k--)
//				inv[k] = inv[k-1];
//			inv[i] = invtmp;
//		}
//	}
	return inv;
}

int sort_item(object ob1, object ob2)
{
	string file1,file2;
	if(userp(ob1) && !userp(ob2)) return 1;
	if(!userp(ob1) && userp(ob2)) return -1;
		
	file1=base_name(ob1);
	file2=base_name(ob2);
	if(file1==file2)
	{
		return getoid(ob2)-getoid(ob1);
	}
	return strcmp(file1,file2);
}
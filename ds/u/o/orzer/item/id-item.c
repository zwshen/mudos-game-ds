//寫好玩的...
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name("祭靈石",({"gilin stone","stone"}));
    set("long","墓碑，能給某人(givename)刻字喔。\n");
    set("unit","個");
    set("value",99999);
    set("no_get",1);
    set("no_sac",1);
    setup();
}
void init()
{
        add_action("do_ids","ids");
} 
  

int do_ids(string arg)
{
        int i, j;
        object obj, *inv,me=this_player(),who;
        string *id,str,tar,obs;

        if( !arg ) {
                inv = all_inventory(me);
                if( !sizeof(inv) )
                        return notify_fail("你身上沒有任何東西。\n");
        write( "你(妳)身上攜帶物品的別稱如下(右方) :\n");
                for(i=0; i<sizeof(inv); i++) {
                        if( !me->visible(inv[i]) ) continue;
                        if(inv[i]->query("secured")) str=" (保護中)"; else str="";
                        printf("%-20s = %s\n", inv[i]->name()+str,
                                implode(inv[i]->parse_command_id_list(), ", ") );
                }
                return 1;
        }
    
        if(sscanf( arg,"%s %s",tar,obs)==2)
        {
          who=find_living(tar);
          if(who) obj=present(obs,who);
        }
        else if(arg!="here")
              obj=present(arg,environment(me));
        else obj=environment(me);
        if(obj) {   
                inv = all_inventory(obj);
                if( !sizeof(inv) )
                        return notify_fail("這裡沒有任何東西。\n");
                write( "在"+obj->name()+", 生物及物品的(英文)名稱如下 :\n");
                        for(i=0; i<sizeof(inv); i++)
                        {
                                if(!me->visible(inv[i]) ) continue;
                                printf("%-20s = %s (檔案:%s.c)\n", inv[i]->name(),
                                implode(inv[i]->parse_command_id_list(), ", "),base_name(inv[i]));
                        }
                        return 1;
        }
         else return notify_fail("沒有這個東西。\n");
}



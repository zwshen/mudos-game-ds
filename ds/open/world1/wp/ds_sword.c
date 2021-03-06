#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;

void create() {
        set_name("虎吼", ({ "tiger roar","roar", "sword"}) ) ;
        set("long",@LONG
暗金剛器的劍型態，名為「虎吼」。
你可以再試著<change>其他型態，或是change staff回到暗金剛器原形。
LONG
);
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",15);
        set("limit_con",15);
        set("limit_int",15);
        set("limit_dex",15);
        set("unit", "把");        
        set("value",1000);
        set("volume",4);        
        set("material","darksteel"); 
        set("replica_ob",__DIR__"../wp/steel_staff");      
               }       
        set("weapon_prop/int",-1);
        set("weapon_prop/dex",2);
        init_sword(60);
        setup();
 }

void init()
{
add_action("change_weapon","change");
}

int change_weapon(string arg)
{
 object me,staff,dagger,pike,whip,fist,obj;
 me=this_player();
 obj=this_object();
 if(this_player()->query("mp") > 300) 
  {switch(arg){
            case "staff":
            {
            write(HIY"你開始將暗金剛器拆解，並重新組合...\n"+
                            "經過一番努力，你將之恢復成"HIC"暗金剛器原型...\n"NOR);
            me->receive_damage("mp",200);
            staff=new_ob(__DIR__"../wp/ds_staff"); 
            staff->move(me);
            destruct(obj);
            return 1;
            }
            case "dagger":
            {
            write(HIY"你開始將暗金剛器拆解，並重新組合...\n"+
                            "經過一番努力，你組合出"HIC"暗金剛器之匕首型--龍咬...\n"NOR);
            me->receive_damage("mp",200);
            dagger=new_ob(__DIR__"../wp/ds_dagger"); 
            dagger->move(me);
            destruct(obj);
            return 1;
            }
            case "pike":
            {
            write(HIY"你開始將暗金剛器拆解，並重新組合...\n"+
                            "經過一番努力，你組合出"HIC"暗金剛器之槍型--鶴啄...\n"NOR);
            me->receive_damage("mp",200);
            pike=new_ob(__DIR__"../wp/ds_pike"); 
            pike->move(me);
            destruct(obj);
            return 1;
            }
            case "whip":
            {
            write(HIY"你開始將暗金剛器拆解，並重新組合...\n"+
                            "經過一番努力，你組合出"HIC"暗金剛器之鞭型--蛇牙...\n"NOR);
            me->receive_damage("mp",200);
            whip=new_ob(__DIR__"../wp/ds_whip"); 
            whip->move(me);
            destruct(obj);
            return 1;
            }
            case "fist":
            {
            write(HIY"你開始將暗金剛器拆解，並重新組合...\n"+
                            "經過一番努力，你組合出"HIC"暗金剛器之拳套型--豹\爪...\n"NOR);
            me->receive_damage("mp",200);
            fist=new_ob(__DIR__"../wp/ds_fist"); 
            fist->move(me);
            destruct(obj);
            return 1;
            }
       default: write("沒有這種型態。\n");
                return 1;
       }
}
else
{
  write("你的法力不足以啟動變型的力量。\n");
  return 1;
}
}


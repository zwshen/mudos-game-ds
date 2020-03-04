#include <ansi.h>
inherit HOUSE;
void create()
{
        set_name("指揮中心",({"command center","center"}));
        set_short("指揮中心","指揮中心內部");
        set_long(@OUTLONG
這棟指揮中心十分巨大，在指揮中心有許多科學家跟機器人
在走動，似乎十分的忙錄，指揮中心能研製各類的生產用工
具(produce)，有了這些工具才能進一步的改造其他類建築。
OUTLONG
,@INLONG
這裡空空蕩蕩的十分寬敞，一個相當普通的建築物。
INLONG
); // 長敘述
        set_weight(999999);
        set("light",1);
        set("no_clean_up",1);
        setup();
}
void init()
{ 
         add_action("do_produce","produce");
}
int do_produce(string arg)
{
    string list;
    object me;
    me=this_player();
    switch(arg) {
      case "1":    //機械手臂
          message_vision("$N向主電腦下了一個指令，指揮中心即開始製造機械手臂。\n",me);
          this_object()->set_temp("makename","機械手臂");
          call_out("make",2,arg);
          break;
      case "2":    
          break;
      default:
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                         工具種類 :                       �鱋n";
          list += "�礜w─────────────�煍w─────────────�瀵n";
          list += "��1.  機械手臂(Engine Arm)    ��2.                          �鱋n";
          list += "�譀����������������������������������������������������������瀵n";
          list += "�灟Y需要建造工具輸入：  produce <代號> 即可。               �鱋n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      }
    return 1;
}
int make(int arg)
{
    object obj,nnew;
    obj=this_object();
    if(obj->query_temp("makenow") <= 100 )
    {
          obj->set_short("研發"+HIW+obj->query("makename")+HIR"(完成度："+obj->query("right")+"%)"NOR"  指揮中心","指揮中心內部" );
       obj->add_temp("makenow",10+random(10));
       call_out("make",2,arg);
    }
    else {
      switch(arg) {
        case "1":    //機械手臂
            message_vision(HIW"指揮中心內科學家叫道：機械手臂！研發完成！\n"NOR,obj);
            set_short("指揮中心","指揮中心內部");
            nnew=new(__DIR__"obj/arm");
            nnew->move(environment(obj));
            break;
        default:
            break;
      }
      obj->delete_temp("makenow");
    }
    return 1;
}
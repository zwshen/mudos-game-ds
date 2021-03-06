#include <ansi.h>
inherit NPC;

void create()
{
        set_name("吟頌者",({"reciter"}) );
        set("long","
暗斯德塔的吟頌者, 他們的工作就是背頌指定的書籍, 為啟發世人的智
慧所努力, 常常有拜訪者從他們的頌讚聲中得到啟示, 他們的吟哦聲中
往往有著對諸神的禮讚.\n"
        );
        set("age",21);
        set("level",7);
        set("int",12);
        set("race","人類");
        set("attitude", "peaceful");
        set("unarmed",15);    //用在mob上的...
        set("dagger",15);    //用在mob上的...
        set("chat_chance",15);
        set("chat_msg",({
        "吟咒者抑揚頓挫的吟誦道：「龍蝦大大好帥 ~~」。\n",
        "吟咒者抑揚頓挫的吟誦道：「隱塵長的像饅頭 ~~」。\n",
        "吟咒者抑揚頓挫的吟誦道：「老林罵人像切菜 ~~」。\n",
        (:command("think"):),
        (:command("ponder 「下一句忘了...」"):),
        "吟咒者抑揚頓挫的吟誦道：「烏漆嗎黑瘦不拉機 ~~」。\n",
        "吟咒者抑揚頓挫的吟誦道：「變臉大大戴牙套 ~~」。\n",
        "吟咒者抑揚頓挫的吟誦道：「ㄣ大大老色魔 ~~」。\n",
        "吟咒者抑揚頓挫的吟誦道：「小凱好可愛 ~~」。\n",
        "吟咒者雙眼看著天空, 虔誠的道：「英特瑟吾神, 吾輩誠心的讚美你的恩德, 感謝您賜予這世界寶貴的知識」。\n",
        }) );
        setup();                
        carry_object(__DIR__"wp/dagger.c")->wield();
        add_money("coin",50);
}

void die()
{
  int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob ) 
        {
                ::die();
                return;
        }
  i=ob->query_temp("DST/hatred");
  if(ob->query_temp("DST/hatred")==0)
  {
        message_vision(HIW"吟頌者淒厲的慘叫聲傳了出去...\n"NOR,ob);
        message_vision(HIY"暗斯德塔塔頂的闇精靈怨靈同時尖聲嘶吼：「暗斯德塔遭到"HIR""+ob->name(1)+""HIY"的入侵！！」\n"NOR,ob);
        message_vision(HIR"智慧之神英特瑟(God of Wisdom-Intser)憤怒的聲音自天上傳來：元素法師、索蘭尼亞騎士們，
追殺"+ob->name(1)+"讓他的靈魂遭到懲罰！！\n"NOR,ob);
  }
  ob->set_temp("DST/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}


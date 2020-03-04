#include <path.h>
#include <ansi.h>
inherit NPC;
void create()
{
 set_name("市井無賴",({"vagabond",}));
 set("long",@LONG
一個處處可見的市井無賴, 但他獐頭鼠目的樣子讓你看了尤
其討厭.
LONG
    );
 set("attitude", "peaceful");
 set("age",41);
 set("gender","男性");
 set("level",20);
 set("chat_chance",10);

set("chat_msg", ({"市井無賴壓低聲音道:哪天把林老頭的 "+HIY+"寶貝"+NOR+" 給摸來!!. \n",
                          "市井無賴發現你在看他, 惡狠狠的朝你瞪了一眼.. \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"../eq/cloth")->wear();
 carry_object(__DIR__"../wp/longsword")->wield();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->query("id") == "gold tackle")
        {
                if(obj->is_busy() )
                {
                        command("whisper "+who->query("id")+" 老子沒空, 龜兒子等一下。\n");
                        return 0;
                }
                message_vision("$N給了市井無賴一個 "+ob->query("name")+"。\n",who);
                command("hehe");
                obj->start_busy(10);
                obj->set_temp("give_tackle",1);
                destruct(ob);
                call_out("give_tackle",1,obj);
                return 1;
        }
}

void give_tackle()
{
      int i;
      object me,obj,thing;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("give_tackle");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？龜兒子人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"市井無賴望著手中的金絲漁網, 得意的笑了笑...\n"NOR);
            obj->set_temp("give_tackle",i+1);
            call_out("give_tackle",2,me);
            break;
          case 2:
            command(CYN"say 嗯...龜兒子你等一等.."NOR);
            obj->set_temp("give_tackle",i+1);
            call_out("give_tackle",2,me);
            break;
          case 3:
            say(CYN"市井無賴看著金絲漁網, 口中喃喃念道: 純金的呢....。\n"NOR);
            obj->set_temp("give_tackle",i+1);
            call_out("give_tackle",3,me);
            break;
          case 4:
            message_vision(CYN"$N對$n說道: 兄弟果然不簡單, 上次老大給了我一個徽記...\n"NOR, this_object(), me);
            obj->set_temp("give_tackle",i+1);
            call_out("give_tackle",2,me);
            break;
          case 5:
            command("say 也不知道是幹啥勞什子的, 就送給你做紀念吧....:Q");
            obj->set_temp("give_tackle",i+1);
            call_out("give_tackle",2,me);
            break;
          case 6:
            thing=new(PAST"obj/mark");
            thing->move(obj);
            command("give mark to "+ me->query("id") );
            obj->delete_temp("give_tackle");
            break;
          }
}

void init()
{
       add_action("typeask","ask");
}
int typeask(string arg)
{
        object me;
        me=this_player();
        if( arg != "vagabond about 寶貝" ) return 0;
        if( me ->query("evil") >= 0 )
        {
                message_vision("市井無賴跟$N說: 看來咱們也是同道...\n\n",me);
                message_vision("市井無賴跟$N說: 就跟你說了吧!!.\n\n",me);
                message_vision("市井無賴跟$N說: 林老頭家裡不是有樣亮亮的東西麼?聽說那可值上萬貫呢!!\n\n",me);
                message_vision("市井無賴跟$N說: 只要兄弟可以拿來給我, 少不了你的好處哩 !!\n\n",me);
        }
        else message_vision("市井無賴不屑的哼了一聲, 嘴裡喃喃說道: 就是討厭你們這種正人君子...\n",me);

        return 1;
}


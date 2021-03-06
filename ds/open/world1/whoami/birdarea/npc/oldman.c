#include <ansi.h>

inherit NPC;
void create()
{
        set_name("老人",({ "old man","man" }) ); 
        set("long","一個居住在獵狐村的老人，據說他年輕時似乎殺過不少的狐狸，\n"
                   "好像還去過傳說中的狐穴，不過這些多半無法查證了•\n");
        set("race","人類");
        set("title",HIR"獵狐村"NOR);
        set("age",60+random(20));
        set("level",25);
        set("attitude","friendly");

        set_skill("dodge",50);
        set_skill("unarmed",50);
        set_skill("parry",50);
      
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
                                (:command,"say 我可是老當益壯呢！想試試看嗎？":),
        }));
        set("chat_chance",20);
        set("chat_msg", ({
                          (:command("sing") :),
                          (:command("yawn"):),
        }));
        setup();
        add_money("coin",500+random(500));           
        set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
}

void init()
{
  add_action("do_no_ask","ask");
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}
void relay_say(object me, string str)
{ 
  object who = this_player();  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"狐狸") != -1)
  { 
    command("oh"); 
    command("say 我在狐穴裡殺了不少的狐狸呢！"); 
    command("think");  }   
  if(strsrch(str,"狐穴") != -1)
  { 
    command("fear"); 
    command("say 說到那我就覺得恐怖！"); 
    command("say 那裡可真的是個詭異的地方呢！");
    command("say 裡面有著火狐狸，冰狐狸，瘋狐狸，毒狐狸，還有就是難走的迷宮！");  }   
  if(strsrch(str,"火狐狸") != -1)
  { 
    command("fear"); 
    command("say 火狐狸喔.."); 
    command("say 它可是會對攻擊他的人噴出火燄的..");
    command("say 我身上就還留著被燒傷的痕跡..");
  }   
 if(strsrch(str,"冰狐狸") != -1)
  { 
    command("fear"); 
    command("say 冰狐狸喔.."); 
    command("say 它可是會對入侵者吐出寒氣，讓他凍的呼天搶地的..");
    command("sigh"); 
    command("say 跟我同行的人，就有一個被它殺了..");
  }   
 if(strsrch(str,"瘋狐狸") != -1)
  { 
    command("fear"); 
    command("say 瘋狐狸喔.."); 
    command("say 千萬別惹到它！");
    command("say 要是他發起瘋來，那可是很恐怖的呢！");
  }   
 if(strsrch(str,"毒狐狸") != -1)
  { 
    command("hmm"); 
    command("say 說實在的..毒狐狸..我也還沒見過呢.."); 
    command("say 這是我看地上的屍體似乎有著中毒的跡象而做的推測..");
  }   
 if(strsrch(str,"迷宮") != -1)
  { 
    command("say 狐穴本身就是個大迷宮啊.."); 
    command("say 根本沒一定路可循..我們要出發前問了好幾個人..他們的走法都不相同..");
    command("say 而且在走的時候，還會嗅到陣陣的血腥味，搞得你頭昏腦漲的..");  
    me->set_temp("can_enter",1); }   
 if(strsrch(str,"走法") != -1)
  { 
    command("say 就跟你說都不一樣了咩.."); 
    command("eh " +who->query("id"));
 }   
 if(strsrch(str,"同行的人") != -1)
  { 
    command("hmm"); 
    command("say 跟我們一起出發的人，只剩兩個人回來，一個就是我，另一個就是這個村的英雄..");
 }   
 if(strsrch(str,"英雄") != -1)
  { 
    command("oh"); 
    command("say 他跟九尾打鬥的過程還真是精彩啊！你沒看到真是太可惜了！"); 
    command("say 最後他還拔下了九尾的一顆牙齒呢！");
 }   
return;
}


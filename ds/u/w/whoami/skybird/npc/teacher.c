#include <net/dns.h>
#include <ansi.h>
inherit NPC;

string *teach_msg = ({
"人身上有十二經絡，以應十二個月，有三百六十五節，以應一歲•","人身上有三百六十一個穴道，分佈在十二條「正經」和任、督兩條脈上•","三里內庭穴，曲池合谷接，委中配承山，太沖崑崙穴，環跳與陽陵，通裡並列缺•",
"合擔用法擔，合截用法截，三百六十穴，不出十二訣。",
"治病如神靈，渾如湯潑雪，北斗降真機，金鎖教開徹。至人可傳授，匪人莫浪說。",
"雖然有三百六十個穴之多，不出這十二個穴，只要補瀉的處方正確，就什麼病都能治了。",
"這些穴道是北方之神所傳授的。因此，針一扎進穴道，連金鎖都可以打開。","至人可傳授，匪人莫浪說，就是說，只能夠教給那些好的弟子，不是好弟子，就不能教他。",
"三里穴：屬於足陽明胃經的合穴，它是一個非常重要的穴道，可用以保養，也可用以治病的重要穴道•",
"內庭穴：是足陽明胃經的滎穴，它在腳的第二指、第三指的中間的這個腳丫子上五分，最主要可用以治療四肢冰冷的現象•","曲池穴：是在手肘上面的手陽明大腸經的合穴，找尋的方法是：手臂稍微彎曲起來，把手掌對著自己的心臟，手臂上最高的這一條經絡線就稱為「手陽明大腸經」，在這個經絡上面的手肘彎彎處的穴道就叫做「曲池穴」•",
"合谷穴：手陽明大腸經的原穴，原氣駐留的穴道，是在身體上的一個非常大的穴道，位置在大拇指跟食指的中間這個虎口，虎口開叉的上面一寸。","崑崙穴：屬於足太陽膀胱經的經穴，「馬丹陽天星十二穴」當中有3個膀胱經的穴道，委中、承山還有崑崙，位置在足外踝的後方與足跟筋的中間•",
"環跳穴：是在膽經的穴道，在臀部腰下頭胯的樞紐上側邊，是一個滿大的穴道，環跳穴上面的肌肉非常的肥厚，要用很長的針才能扎到穴位，有的時候甚至要用到六寸長的針。",
"陽陵泉：足少陽膽經的合穴，膝的前下方有一條骨叫脛骨，脛骨後面的一條骨，叫做「輔骨」，輔骨的莖突也就是一個小骨頭，這個小骨頭的前下方，有個洞，就稱之為陽陵泉。",
"通裡穴：是心經的絡穴，在手腕上方一寸，也就是神門上一寸的位置，此穴可以治療「欲言聲不出」以及懊惱怔忡這一類的心理層面的毛病。","列缺穴：是肺經的絡穴，叉交大拇指與食指，而食指指到在手腕的上側的撓骨邊緣就是這個穴，可用以治偏頭痛，還可以治療遍身麻痺•",
});

void do_teach();
void create()
{
  set_name("東代山",({"teacher"}) );
  set("long","\n");
  set("age",58);
  set("level",25);
  set("gender","男性");
  set("race","人類");
  set("chat_chance",30);
  set("chat_msg",({
  (: do_teach :),
  (: do_teach :),
  (: do_teach :),
  (: do_teach :),
  }));
  set("talk_reply","想學有關穴道方面的知識就請坐(sit)吧•\n");
  setup();
}

void init()
{
  ::init();
  add_action("do_sit","sit");
  if (this_player()->query_temp("do_sit") ) this_player()->delete_temp("do_sit");
  this_object()->set_heart_beat(1);
}

void do_teach()
{
  object ob = this_object(), *student;
  int i;

  if(ob->is_fighting() ) return;
 
  student = all_inventory(environment(ob));
  if( sizeof(student) < 1 ) return;

  command("say " +teach_msg[random(17)] );

  for(i=0;i<sizeof(student);i++)
  {
    if( userp(student[i]) && student[i]->query_temp("do_sit") )
    {
       if( student[i]->query_temp("netdead") == 1 ) continue;
       if( student[i]->query_skill("acupuncture_cognition") > 70 ) continue;
       if(random(4))
       {
         message_vision(CYN"對於老師的一番話，$N似乎若有所悟。\n"NOR,student[i] );
         student[i]->improve_skill("acupuncture_cognition",random(student[i]->query_int())+1);
         if (student[i]->query("class1") == "天梟教")
         student[i]->improve_skill("acupuncture_cognition",random(student[i]->query_int())*2);
       }
    }
  }
  return;
}

int do_sit()
{
  object me;
  me=this_player();
 
  if(me->query_temp("do_sit")) return notify_fail("你已在學習穴道認知了。\n");
  if (me->is_fighting() ) return notify_fail("你正忙著打架，沒空學穴道認知。\n");
  if(me->is_busy() ) return notify_fail("你正忙著，沒有空學穴道認知•\n");

  message_vision("$N找了個空位坐下，開始學穴道認知了。\n",me);
  me->set_temp("do_sit",1);
  return 1;
}


#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"黃心"NOR, ({ "hown heart","heart" }) );
        set("level",40);
        set("combat_exp",20000);
set("exp",20000);
        set("evil",200);
        set("long",@LONG
   黃心本是個樸實而勤奮的農夫,顧家,顧妻,顧子
女,又對長輩孝順的他,是人人偕之的大男人,打
獵,劈柴,挑水,樣樣精通,最喜歡用空手,雙手非常
的靈活,但是有一天,他到森林裡去打獵,誤把蚩
尤當成獵物,向前撲了過去,蚩尤發覺立刻轉身
抽起了 虎魄 向前應戰,但是卻發生了一件事,蚩
尤每每要砍中黃心時,卻每每被黃心用雙手撥開
,黃心見狀不對,拔腿就跑,蚩尤卻猛追在後,速度
沒有蚩尤快的他,馬上就被追上了,蚩尤使出了忿
怒的一擊,黃心躲避不及,再次用雙手想樣撥開,但
這種把戲,已經被蚩尤看破了, 虎魄 飄浮不定,黃心
一不小心,被 虎魄 割到背部, 虎魄 開始把邪力不
斷的送到黃心體內,過不了多久,黃心雙眼變紅,肌
肉隆起,蚩尤見他不錯,收他為手下,被 虎魄 感染的
他,也爽快的答應了,蚩尤賜給他一對地神兵,取名
為耀日爪,從此就跟著蚩尤了 
LONG          );
        set("age",1946827);
        set("attitude","killer");
        set("gender","男性");
        set("title",HIG"蚩尤護衛"NOR);
        set_skill("unarmed",80);
        set_skill("dodge",100);
        set_skill("parry",80);
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
"黃心說:護駕 ~ ~ ~ ~ 護駕 ~ ~ ~ ~。\n\n",
"黃心說:可以打倒落紅..蠻不錯的嘛.. !! 。\n\n"                       }) );
       setup();
       carry_object("/u/t/tako/sunfist.c")->wield();
}






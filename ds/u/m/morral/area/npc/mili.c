#include <ansi.h>
    inherit NPC;
object user=this_player();
    void create()
{
set_name(HIG"精靈米莉"NOR,({"elf mili","elf"}) );
set("gender", "女性");
set("attitude","peaceful");
set("age",5620);
set("long", "她有著你想像中的一切精靈所擁有的容貌─
長髮、碧眼、長耳、略帶著螢光的金黃色頭髮，顯然是來引導你的。\n");
set("level",120);
set("evil",-5000);
set_skill("dodge",100);
set_skill("sword",100);
set_skill("parry",100);
set_skill("block",100);
set("chat_chance",50);
set("chat_chance_combat",50);
set("chat_msg_combat",({
(:command,"say 嘻嘻，你是打不過我的ㄡ。":),
}));
set("chat_msg",({
(:command,"say 我是未來的引導者─米莉ㄡ":),
(:command,"say 你們一切都要聽我的ㄡ":),
(:command,"hmm":),
(:command,"say 不管怎樣，先往前走吧，看看再說。":),
(:command,"smile":),
}) );
  setup();
set("coin",random(5000)); 
}

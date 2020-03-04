#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("º»¨ò",({"jailer"}));
       set("gender","¤HÃþ");
       set("level",40);
       set("age",40);      
       set("attitude","friendly");  
       set("evil",20);
       set("long",@LONG      
º»¨ò¡C
LONG
); 
        setup();  
        carry_object(__DIR__"obj/fork")->wield();
} 


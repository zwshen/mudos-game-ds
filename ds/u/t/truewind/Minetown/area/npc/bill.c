// Npc: /u/t/truewind/npc/1.c

inherit NPC;

void create()
{
	set_name("大比爾", ({"Big Bill","Bill"}) );
	set("long", "酒館的老闆，油頭肥面的瑞曼人，笑起來一口獠牙白的可怕。
你如果想知道這附近發生的事情，可以試著跟他聊聊(talk with bill)。\n");
	set("race", "人類");
	set("age", 150);
	set("level", 25);
        set("title", "酒店老闆");
        set("chat_chance", 5);
        set("chat_msg", ({
       (: command("hehe") :),
       (: command("say 今天有不少客人啊...") :),
}));


	setup();

}


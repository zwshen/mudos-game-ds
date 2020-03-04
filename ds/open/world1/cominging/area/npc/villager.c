inherit NPC;
void create()
{
	set_name("傲沖村村民",({ "villager" }));
	set("long",
		"這是傲沖村中常見的村民，他們的身上都流滿了黏答答的汗，可見他\n"
		"們的辛勤和努力。\n"
	);
	set("age",random(10)+30);
	set("level",random(5)+5);
	set("combat_exp",200);
	set("chat_chance",4);
	set("chat_msg",({
  "村民努力的將稻田中的雜草拔除。\n",
  "村民說：加油ㄚ，要撐過今年冬天呀。\n",
  (: random_move :),
}));
	setup();
	carry_object(__DIR__"eq/sandal.c")->wear();
}
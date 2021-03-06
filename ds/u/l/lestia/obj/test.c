inherit NPC;

void create()
{
  set_name("金釵女", ({"jinchai nu", "nu", "girl"}) );
  set("gender", "女性" );
  set("age", 20);
  set("long","一位柳眉粉面含笑，蛾裙領露酥胸的美女。\n");

  set("combat_exp", 2500);
set("define_look","看起來想給你上");
  set("str", 15);
  set("attitude","heroism");

  setup();
  //carry_object("/d/obj/cloth/skirt")->wear();
}

void init()
{
  add_action ("do_sleep","sleep");
  remove_call_out ("says");
  call_out("says",random(3),this_object());
}

void says (object me)
{
  string *msgs = ({
    "$N吃吃一笑，抿嘴看著你。\n",
    "$N含情脈脈地對你說……我……\n",
    "看來$N很想跟你……如果你願意，也請下一次 sleep 命令。\n",
    "$N對著你會心地一笑，點了點頭。\n",
    "$N很想跟你……\n",
    "$N對你婉爾一笑。\n",
  });
  message_vision (msgs[random(sizeof(msgs))],me);
  remove_call_out ("says");
  call_out("says",random(40),me);
}

int do_sleep ()
{
  object me = this_object();
  object who = this_player();
  message_vision ("$N摟著$n柔軟的身體，不由得心醉神迷……\n\n",who,me);
  who->command_function("remove all");
  who->start_busy(3,3);
  remove_call_out ("get_fainted");
  call_out ("get_fainted",1,who,me);
  remove_call_out ("says");
  call_out("says",40,me);
message_vision ("$N摟著$n柔軟的身體，不由得心醉神迷2……\n\n",who,me);
  return 1;
}

void get_fainted (object who, object me)
{
  object *objs = all_inventory(who);
  int i = sizeof (objs);
  message_vision ("$N對$n神秘地一笑。\n\n",me,who);
  who->unconcious();
  while (i--)
  {
    object obj = objs[i];
    message_vision ("$N從$n身上拿出"+obj->query("name")+"。\n",me,who);
    obj->move(me);
    destruct(obj);
  }
}


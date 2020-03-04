inherit ROOM;
void create()
{
  set ("short", "水裡");
  set ("long", @LONG

這條江叫作磐龍江，因江水過於湍急，無船家願於此江擺渡。

LONG
);
  set("no_recall",1);
  set("no_goto",1);
  setup();
}

int room_effect(object me)
{
  object *env;
  int i;
  env = all_inventory();
  for(i=0;i<sizeof(env);i++)
  {
    if(env[i]->query_temp("fly")) continue;
    if( env[i]->query_temp("float") && random(3) ) continue;
    if(userp(env[i])) continue;
    if(living(env[i]))
    {
      message_vision("$N一個不小心，被湍急的水流捲走了。\n",env[i]);
      message_vision("\n$N大叫:救命啊! 救命啊!\n\n",env[i]);
    }
    else message_vision("$N被水沖走了。\n",env[i]);
    destruct(env[i]);
    if(!random(3)) break;
  }
  return 1;
}

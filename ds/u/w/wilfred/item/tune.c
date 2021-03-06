inherit ITEM;
void create()
{
  set_name("工具集",({"tools"}));
  setup();
}

void init()
{
  add_action("do_add","atune");
}

int do_add(string target)
{
  object me;
  string p,arg;
  string *tuned_ch;

  if( !target )
    return notify_fail("指令格式: atune 某人 [目標頻道]\n");

  if(sscanf(target,"%s %s",p,arg) == 2 )
  {
    me = find_player(p);
    if(!me) return notify_fail("找不到此人\n");

    tuned_ch = me->query("channels");
    if( pointerp(tuned_ch) && member_array(arg, tuned_ch) != -1 )
    {
      write(me->query("name")+"關閉 " + arg + " 頻道。\n");
      tuned_ch -= ({ arg });
      me->set("channels", tuned_ch);
      return 1;
    }
    else
    {
      if(CHANNEL_D->can_tune(arg,me))
      {
        tuned_ch += ({ arg });
        me->set("channels", tuned_ch);
        write(me->query("name")+"開啟 " + arg + " 頻道。\n");
      }
      else write(me->query("name")+"無法開啟這個頻道。\n");
      return 1;
    }
  }

  me = find_player(target);
  if(!me) return notify_fail("找不到此人\n");
  tuned_ch = me->query("channels");

  if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
    write(me->query("name")+"現在並沒有收聽任何頻道。\n");
  else
    write(me->query("name")+"現在收聽的頻道﹕" + implode(tuned_ch, ", ") + "。\n");
  return 1;
}


inherit NPC;

void create()
{
  set_name("�h�x", ({"lower deck","deck"}));
  set("long",@long
�@�Ӭ��⪺�p�k�ġA���b���Ǫ��C���C
long);      
  set("gender", "�k��" );
  set("age",12);
  set("level",3);
  set("race","human");
  set("title",HIC"���x"NOR);
  set("chat_chance", 5);
  set("chat_msg", ({
      "�̤l�N�@���ļߩ�b�L�ڡA�@�䨫�@��j�۪��C\n",
      "�̤l���ۤp��K��B�]�Ӷ]�h�C\n",
      "�̤l���D�G�x�H�ڪ����߶���O�H�H�a���W�������߰������A������h�F�C\n",
      "�̤l�C���Y�j�M�|�P�A�n���b��M����C\n",
       (: command,"go south" :),
       (: command,"go north" :),
     }));
  setup();
  add_money("coin",10+random(10));
}

int accept_object(object who,object ob)
{
  object obj,page;
  obj=this_object();

  if(ob->query("id") == "seashell necklace")
  {
    if(obj->is_busy() || obj->is_fighting())
      {
        command("whisper "+who->query("id")+" �ڨS�šA�O�ӷЧڡC\n");
        return 0;
      }
    message_vision("$N�����̤l�@�� "+ob->query("name")+"�C\n",who);
    command("jump");
    message_vision("�̤l���D�G���§A�A�A��^�F�ڪ�����A�ڦ��@�i���_�ϳ�A���A�C\n",who);
    obj->start_busy(3);
    destruct(ob);
    page=new_ob(__DIR__"eq/neck-design-page");
    page->move(obj);
    command("give page to "+ this_player()->query("id") );
    return 1;
  }
  return 0;
}
inherit NPC;

void create()
{
        set_name("����", ({ "dove" }) );
        set("race", "���~");
        set("age", 2);
     set("level",5);

        set("long", "�@�����áA�b�����H�B�i���C\n");
        
   set("str",1);
      set("max_hp",100);
    set("dex",-3);
     set("int",1);
       set("con",5);

        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "���ð֤F�֦a�W���p�ۤl�C\n" }) );
                

        setup();
}

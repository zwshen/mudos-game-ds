// In room073.c �Ϯ��]
#include <path.h>
inherit NPC;

void make_mark();

void create()
{
	set_name("�Ϯ��]�]��",({"library member","member"}) );
	set("long","�o��Ϯ��]���O���u�q���]���C\n");		
	set("age",23);
	set("level",3);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-5);		// ���c�� -5 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say �Ϯ��]�O�j�a���z���_�w�A�w��j�a�h�h�Q�ΡI"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",5);
	set_skill("block",5);
	set_skill("parry",8);
	set_skill("unarmed",10);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");

	set("bookroom",SHENGSAN2"aovandis/bookroom");

	setup();

	add_money("dollar",40);
}

void init() 
{
	::init();
	add_action("do_borrow","borrow");
	add_action("do_return","return");
}

int do_borrow(string arg)
{
	object me,book;
	string *item,bookname;
	int bookno,i,tmp,bookdate;

	me = this_player();

	if(!arg) return notify_fail("�A�n�ɤ���ѩO?\n");
	if(sscanf(arg,"book%d",bookno)!=1) return notify_fail("�A�n�ɤ���ѩO?\n");
	if(book=present(arg,me))
	{
		item = me->query("aovandis/library");
		for(i=0;i<sizeof(item);i++)
		{
			if(sscanf(item[i],"book%d_%d",bookno,bookdate)!=2)
				continue;
			bookname = "book"+(string)bookno;
			if(bookname == arg)
				tmp = 1;
		}
		if(tmp)
			command("say �A�w�g�ɹL "+arg+" �F�C");
		else
		{
			me->add("aovandis/library",({arg+"_"+time()}));
			message_vision("$n��y"+book->query("name")+"�z�浹�F $N�C\n",me,this_object());
			message_vision("$n�N�y"+book->query("name")+"�z���F���ϫ���ٵ��F $N�C\n",me,this_object());
		}
	}
	else
		command("say �A���W�èS�� "+arg+" ���H");
	return 1;
}

int do_return(string arg)
{
	object bookroom,me,book;
	string bookname,*item;
	int i,tmp,gotit,bookno,bookdate;

	me = this_player();

    if( !arg ) return  notify_fail("�A�n�k�٤���ѩO?\n");
	if(sscanf(arg,"book%d",bookno)!=1) return notify_fail("�A�n�k�٤���ѩO?\n");
	if(!bookroom=load_object(this_object()->query("bookroom"))) return 0;

	if(book=present(arg,me))
	{
		item = me->query("aovandis/library");
		for(i=0;i<sizeof(item);i++)
		{
			if(sscanf(item[i],"book%d_%d",bookno,bookdate)!=2)
				continue;
			bookname = "book"+(string)bookno;
			if(bookname == arg)
			{
				gotit = i;
				tmp = 1;
			}
		}
		if(!tmp)
			command("say �A�S���ɹL "+arg+" ��C");
		else
		{
			me->delete("aovandis/library",({arg+"_"+time()}));
			message_vision("$n��y"+book->query("name")+"�z�浹�F $N�C\n",me,this_object());
			message_vision("$n�N�y"+book->query("name")+"�z���F���ϫ���ٵ��F $N�C\n",me,this_object());
		}
			
	}
	else
		command("say �A���W�èS�� "+arg+" ���H");

	return 1;
}

void make_mark()
{
	object *enemy, ob;
	command("say �z�I�ϩR���I");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�A�o�ӥi�Ȫ��c�]�A�A�N�|�����g�@���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}

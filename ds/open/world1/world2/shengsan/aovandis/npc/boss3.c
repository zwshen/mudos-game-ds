// In room120.c �������s��
inherit NPC;
inherit SELLMAN;
void make_mark();
string askboss();

void create()
{
	set_name("�s������",({"clerk"}) );
	set("long",@LONG
	�o�쩱���հs���\\�O�i�O�@���@���C
	==========================
	���~�M��	list
	�ʶR���~	buy <���~>
	==========================
LONG);		
	set("age",32);
	set("level",10);
	set("race","human");
	set("gender","�k��");
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say ���N�O�o�Ӵ�����"):),
		(:command("say ��کҽժ��s�O�̦n�ܪ���n���n�|�|����"):),
		(:command("say �o�a��������Q�����A�]�����D�]����h�F�A�w�g���n�Ǥ�l�S�ݨ�o�F�C"):),
	})	);

	set("inquiry/����Q","��C����Q�ڡA�o�s�u�����v�A�ܦnť�a�C" );
	set("inquiry/����",(: askboss :) );

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",10);
	set("sell_list",([
  "/open/world2/obj/bloodmarry_wine" : 10,
"/open/world2/obj/bluegimi_wine" : 15,
"/open/world2/obj/beer" : 5,
]));
	set("talk_reply","��A�n��ڲ�ѡH�ߤW��ڮa�a�C");
	setup();

	add_money("dollar",200);
}

string askboss()
{
	return "���A�w�g�֤@�Ӥ�S�ݨ�o�F�A�u�����D�o�b������H";
}

void make_mark()
{
	object *enemy, ob;
	command("say �ϩR���I�ϩR���I");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�O���]���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}

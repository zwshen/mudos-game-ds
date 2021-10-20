//	skill.c
//
// 	This is the standard skill daemon object. All objects defining a skill
//	should inherit this as its skeleton.
// #pragma save_binary
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int is_skill() { return 1; }

//
// valid_learn()
//
// This function is to check if a character should be able to 
// learn/study/practice the skill. The default function just
// returns 1 to allow any characters improve the skill. However,
// a good skill should has its own feature and restriction. Redefine
// this function in your skill object and make it reasonable 
// according to the power of the skill.

int valid_learn(object me) { return 1; }


//�s�W: �ޯ�W��
//�b�ޯत�i�ۦ�w�q���禡, �P�_����me�i�ǲߪ��W��(�Ǧ^��),�o�ӭȷ|��
//�b improve_skill(spell) ��add_skill(spell) �P�_�O�_��W�[�ޯ൥��.
//
// Luky in DS 5/3/1999
int improve_limite(object me) { return 100; }

int valid_effect(object me, object weapon, string action_name, int skill) 
{ 
	return 1;
}

// 
// type()
//
// This function should return the type of the skill. The skill type now
// affects if the skill requires combat exp in order to be learned (see
// /cmds/std/learn.c ) and the ranking of a skill level (see 
// /cmds/usr/skills.c )�C
// Currently we have only 2 types of skill: "martial" and "knowledge".

string type() { return "martial"; }

//
// skill_improved()
//
// This function is called when a character's skill has gained a new level.
// You can make some modify to a character according to the skill.

void skill_improved(object me) {}

//
// exert_function()
//
//     This function is used by the "exert" command as specific skill's 
// command parser. This function parses the arguments in the standard form
// (that is, exert <function> [<target>]). When <target> is not present,
// use the character himself as default.
//     In order to use this default exert command parser, you must define
// a function called exert_function_file(string func) in the skill object
// that takes the function name as argument and return the file name that
// defines the specified function. 
/*
int exert_function(object me, string arg)
{
	string func, target, file;
	object target_ob;

	if( sscanf(arg, "%s %s", func, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("�o�̨S�� " + target + "�C\n");
	} else {
		func = arg;
		target_ob = me;
	}

	if( !stringp(file = (string)this_object()->exert_function_file(func))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "exert", me, target_ob);
}

int perform_action(object me, string arg)
{
	string action, target, file;
	object target_ob;

	if( sscanf(arg, "%s %s", action, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("�o�̨S�� " + target + "�C\n");
	} else {
		action = arg;
	}

	if( !stringp(file = (string)this_object()->perform_action_file(action))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "perform", me, target_ob);
}
*/
int cast_spell(object me, string spell, object target)
{
	string file;

	
	file="/daemon/spell/"+spell;
	if( file_size(file + ".c") <= 0 )
		return notify_fail("�o�ӥ@�ɤ��S��"+file+"�o�ةG��C\n");

	return (int)call_other( file, "cast", me, target);
}
int cast_spell_dir(object me, string spell, object target, string dir)
{
	string file;
	
	file="/daemon/spell/"+spell;
	if( file_size(file + ".c") <= 0 )
		return notify_fail("�o�ӥ@�ɤ��S��"+file+"�o�ةG��C\n");

	return (int)call_other( file, "cast", me, target, dir);
}
int cast_skill(object me, string force, object target,string arg)
{
	string file;

	
	file="/daemon/skill/"+force;
	if( file_size(file + ".c") <= 0 )
	{
		tell_object(me,"�S������ɮ�\n");
		return notify_fail("�o�ӥ@�ɤ��S��"+force+"�o�اޯ�C\n");
	}
	return (int)call_other( file, "exert", me, target, arg);
}
int cast_skill_dir(object me, string force, object target, string dir)
{
	string file;
	
	file="/daemon/skill/"+force;
	if( file_size(file + ".c") <= 0 )
		return notify_fail("�o�ӥ@�ɤ��S��"+force+"�o�اޯ�C"+file+"\n");

	return (int)call_other( file, "exert", me, target, dir);
}
/*
int conjure_magic(object me, string spell, object target)
{
	string file;

	notify_fail("�A�ҿ�Ϊ��k�N�t���S���o�تk�N�C\n");

	if( !stringp(file = (string)this_object()->conjure_magic_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "conjure", me, target);
}

int scribe_spell(object me, object ob, string spell)
{
	string file;

	if( !stringp(file = (string)this_object()->scribe_spell_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "scribe", me, ob );
}

*/
package cn.jhc.test;

import static org.junit.Assert.*;

import java.sql.Date;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import cn.jhc.model.Clazz;
import cn.jhc.model.Course;
import cn.jhc.model.Score;
import cn.jhc.model.ScorePK;
import cn.jhc.model.Student;

public class SchoolTest {
	private SessionFactory sessionFactory;
	private Session session;
	@Before
	public void testBefore(){
		sessionFactory = new Configuration().configure().buildSessionFactory();
		session = sessionFactory.getCurrentSession();
		session.beginTransaction();
	}
	
	@After
	public void testAfter(){
		session.getTransaction().commit();
	}
	
	@Test
	public void test() {
		
		Student student = new Student();
//		student.setSno(1);
		student.setSname("wjk");
		student.setSex("man");
		student.setClassNo(123);
		student.setBirth(new Date(2015-1900,9-1,25-1));
		session.save(student);
		
		Clazz c = new Clazz();
		c.setClassName("uio");
		c.setCollege("fg");
		c.setEnterYear(2015);
		c.setSpecialty("tk");
		session.save(c);
		
		Course course = new Course();
		course.setCreadit(7.2);
		course.setClassHour(10);
		course.setCname("bdfgr");
		session.save(course);	
	}

	
}

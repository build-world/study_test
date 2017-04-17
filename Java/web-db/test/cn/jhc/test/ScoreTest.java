package cn.jhc.test;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import cn.jhc.model.Score;
import cn.jhc.model.Score2;
import cn.jhc.model.Score2PK;
import cn.jhc.model.Score3;
import cn.jhc.model.Score3PK;
import cn.jhc.model.Score4;
import cn.jhc.model.Score4PK;
import cn.jhc.model.ScorePK;

public class ScoreTest {
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
	public void testScoreSave() {
		Score score = new Score();
		score.setUscore(70);
		score.setEndScore(80);
		ScorePK pk = new ScorePK();
		pk.setCno(1);
		pk.setSno(1);
		score.setPk(pk);
		session.save(score);
	}
	
	@Test
	public void testScore2Save() {
		Score2 score = new Score2();
		score.setUscore(70);
		score.setEndScore(80);
		Score2PK pk = new Score2PK();
		pk.setCno(1);
		pk.setSno(1);
		score.setPk(pk);
		session.save(score);
	}
	
	@Test
	public void testScore3Save() {
		Score3 score = new Score3();
		score.setUscore(70);
		score.setEndScore(80);
		Score3PK pk = new Score3PK();
		score.setCno(1);
		score.setSno(1);
		
		session.save(score);
	}
	
	@Test
	public void testScore4Save() {
		Score4 score = new Score4();
		score.setUscore(70);
		score.setEndScore(80);
		Score4PK pk = new Score4PK();
		pk.setCno(1);
		pk.setSno(1);
		score.setPk(pk);
		session.save(score);
	}
}

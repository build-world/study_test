package cn.jhc.model;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
public class Course {
	private int cno;
	private String cname;
	private double creadit;
	private int classHour;
	
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	public int getCno() {
		return cno;
	}
	public void setCno(int cno) {
		this.cno = cno;
	}
	@Column(length=30,nullable=false)
	public String getCname() {
		return cname;
	}
	public void setCname(String cname) {
		this.cname = cname;
	}
	@Column(precision=1)
	public double getCreadit() {
		return creadit;
	}
	public void setCreadit(double d) {
		this.creadit = d;
	}
	public int getClassHour() {
		return classHour;
	}
	public void setClassHour(int classHour) {
		this.classHour = classHour;
	}
	
}

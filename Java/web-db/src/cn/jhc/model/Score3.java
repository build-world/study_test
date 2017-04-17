package cn.jhc.model;

import javax.persistence.EmbeddedId;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.IdClass;
import javax.persistence.ManyToMany;
import javax.persistence.Table;
@Entity
@Table(name="Score_3")
@IdClass(Score3PK.class)
public class Score3 {
	private int sno;
	private int cno;
	private float uscore;
	private float endScore;
	public float getUscore() {
		return uscore;
	}
	public void setUscore(float uscore) {
		this.uscore = uscore;
	}
	public float getEndScore() {
		return endScore;
	}
	public void setEndScore(float endScore) {
		this.endScore = endScore;
	}
	@Id
	public int getSno() {
		return sno;
	}
	public void setSno(int sno) {
		this.sno = sno;
	}
	@Id
	public int getCno() {
		return cno;
	}
	public void setCno(int cno) {
		this.cno = cno;
	}

	
}

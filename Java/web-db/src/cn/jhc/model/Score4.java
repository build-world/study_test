package cn.jhc.model;

import javax.persistence.EmbeddedId;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.IdClass;
import javax.persistence.ManyToMany;
import javax.persistence.Table;
@Entity
@Table(name="Score_4")
public class Score4 {
	private Score4PK pk;
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
	public Score4PK getPk() {
		return pk;
	}
	public void setPk(Score4PK pk) {
		this.pk = pk;
	}


	
}

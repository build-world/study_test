package cn.jhc.model;

import javax.persistence.EmbeddedId;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.Table;
@Entity
@Table(name="Score_2")
public class Score2 {
	private Score2PK pk;
	private float uscore;
	private float endScore;
	@EmbeddedId
	public Score2PK getPk() {
		return pk;
	}
	public void setPk(Score2PK pk) {
		this.pk = pk;
	}
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

	
}

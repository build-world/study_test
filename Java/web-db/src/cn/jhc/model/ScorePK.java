package cn.jhc.model;

public class ScorePK implements java.io.Serializable{
	private int sno;
	private int cno;
	public int getSno() {
		return sno;
	}
	public void setSno(int sno) {
		this.sno = sno;
	}
	public int getCno() {
		return cno;
	}
	public void setCno(int cno) {
		this.cno = cno;
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + cno;
		result = prime * result + sno;
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		ScorePK other = (ScorePK) obj;
		if (cno != other.cno)
			return false;
		if (sno != other.sno)
			return false;
		return true;
	}
	
	
}

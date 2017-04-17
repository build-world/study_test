package cn.jhc.DB;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


public class DBUtil {
	public static Connection getConnection() {
		try {
			Class.forName(DBContant.DB_DRIVER);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		Connection conn=null;
		try {
			conn =  DriverManager.getConnection(DBContant.DB_URL, DBContant.DB_USERNAME, DBContant.DB_PASSWORD);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		if(conn!=null){
			System.out.println("SQL���ӳɹ� !");
		}else {
			System.out.println("SQL����ʧ�� !");
		}
		return conn;
	}
	
}

package cn.jhc.test;

import java.sql.Connection;

import org.junit.Test;

import cn.jhc.DB.DBUtil;

public class MysqlTest {

	@Test
	public void test() {
		Connection conn =  DBUtil.getConnection();
	}
}

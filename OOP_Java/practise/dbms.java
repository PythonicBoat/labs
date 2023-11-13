import java.sql.*;

public class dbms {

	public static void main(String args[])
		throws SQLException, ClassNotFoundException
	{
		String driverClassName
			= "sun.jdbc.odbc.main";
		String url = "jdbc:odbc:XE";
		String username = "admin";
		String password = "admin";
		String query
			= "create table student if not exist ";

		// Load driver class
		Class.forName(driverClassName);

		// Obtain a connection
		Connection con = DriverManager.getConnection(
			url, username, password);

		// Obtain a statement
		Statement st = con.createStatement();

		// Execute the query
		int count = st.executeUpdate(query);
		System.out.println(
			"number of rows affected by this query= "
			+ count);

		// Closing the connection as per the
		// requirement with connection is completed
		con.close();
	}
} // class
